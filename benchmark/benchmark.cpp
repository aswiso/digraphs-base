#include "benchmark.h"

#include <cstdint>
#include <vector>
#include <iostream>

#include "DiGraph.h"
#include "utils.h"

DiGraph get_random_graph(std::int32_t nodes){
	srand ( time(NULL) );
	DiGraph D;
	// create nodes
	for(int32_t i = 0; i < nodes; ++i){
		D.add_node();
	}
	// connect randomly
	// connection probability 20%
	std::int32_t connection_probability = 20;
	for(std::int32_t i = 0; i < nodes; ++i){
		for(std::int32_t j = 0; j < nodes; ++j){
			if(i == j){
				continue;
			}
			if((std::rand() % 100) < connection_probability){
				D.add_edge(i, j);
			}
		}
	}

	D.export_to_dot_file("tmp_rnd_" + std::to_string(nodes) + ".dot");

	return D;

}

static void benchmark_reachability(benchmark::State& state) {
	const auto n = state.range(0);
	DiGraph D = get_random_graph(n);
	
	for (auto _ : state) {
		state.PauseTiming();

		state.ResumeTiming();
		auto reachability = get_reachability_matrix(D);
		//benchmark::DoNotOptimize(autStat.print());
	}	
}


int main(int argc, char** argv) {
	::benchmark::Initialize(&argc, argv);
	if (::benchmark::ReportUnrecognizedArguments(argc, argv))
		return 1;
	::benchmark::RunSpecifiedBenchmarks();
	::benchmark::Shutdown();
	return 0;
}

BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(10);
BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(20);
BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(30);
BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(40);
BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(50);
BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(60);
BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(70);
BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(80);
BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(90);
BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(100);
//BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(1000);
//BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(10000);
//BENCHMARK(benchmark_reachability)->Unit(benchmark::kMillisecond)->Arg(100000);
