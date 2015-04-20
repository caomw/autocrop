#include "boost/program_options.hpp"
namespace po = boost::program_options;

#include "opencv2/core.hpp"
using namespace cv;

#include "datasets/datasets.hpp"
#include "trainer/train.hpp"
#include "util.hpp"

int main(int argc, char** argv)
{
	/*
	 * Argument parsing
	 */
	po::options_description desc("Available options");
	desc.add_options()
	    ("help", "Show this message")
	    ("headless,hl", po::bool_switch()->default_value(false), "Run without graphical output")
	;

	po::positional_options_description p;
	p.add("input-file", -1);

	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
	po::notify(vm);

	if (vm.count("help")) {
		std::cout << "Usage: " << argv[0]
			<< " [options] input-file" << std::endl
			<< desc;
		return 1;
	}

	if (vm["headless"].as<bool>()) GRAPHICAL = false;

	/*
	 * Run trainer
	 */
	ds::Chen chen;
	Trainer trainer;
	chen.addToTrainer(trainer);
	//trainer.train();

	return 0;

}
