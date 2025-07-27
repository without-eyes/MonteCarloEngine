#ifndef MONTECARLOENGINE_H
#define MONTECARLOENGINE_H

#include <numeric>
#include <thread>

template <typename Experiment>
class MonteCarloEngine {
public:
    explicit MonteCarloEngine(uint64_t trials, double precision) : trials(trials), precision(precision) {}

    double run() {
        const uint8_t threadCount = std::thread::hardware_concurrency();
        uint64_t trialsPerThread = trials / threadCount;
        std::vector<std::thread> threads;
        std::vector results(threadCount, 0.0);

        for (uint8_t i = 0; i < threadCount; i++) {
            threads.emplace_back([&, i] {
                Experiment localExperiment(trialsPerThread, precision);
                for (uint64_t j = 0; j < trialsPerThread; j++) {
                    results[i] += localExperiment.run();
                }
            });
        }

        for (auto& thread : threads) {
            thread.join();
        }

        double result = std::accumulate(results.begin(), results.end(), 0.0);
        return result / trials;
    }

private:
    uint64_t trials;
    double precision;
};

#endif //MONTECARLOENGINE_H