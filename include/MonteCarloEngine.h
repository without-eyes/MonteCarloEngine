#ifndef MONTECARLOENGINE_H
#define MONTECARLOENGINE_H

#include <numeric>
#include <thread>

template <typename Experiment>
class MonteCarloEngine {
public:
    explicit MonteCarloEngine(uint64_t trials, double precision) : trials(trials), precision(precision) {}

    double run() {
        uint64_t threadCount = std::thread::hardware_concurrency();
        uint64_t trialsPerThread = trials / threadCount;
        std::vector<std::thread> threads;

        struct alignas(64) PaddedDouble {
            double val;
            char padding[64 - sizeof(double)];
        };
        std::vector<PaddedDouble> results(threadCount, { 0.0 });

        for (uint8_t i = 0; i < threadCount; i++) {
            threads.emplace_back([&, i] {
                Experiment localExperiment(trialsPerThread, precision);
                for (uint64_t j = 0; j < trialsPerThread; j++) {
                    results[i].val += localExperiment.run();
                }
            });
        }

        for (auto& thread : threads) {
            thread.join();
        }

        double result = std::accumulate(results.begin(), results.end(), 0.0, [](double sum, const PaddedDouble& pd) {
            return sum + pd.val;
        });
        return result / trials;
    }

private:
    uint64_t trials;
    double precision;
};

#endif //MONTECARLOENGINE_H