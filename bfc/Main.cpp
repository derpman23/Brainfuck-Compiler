#include "Utils.h"

int main(int argc, char** argv) {
	Arguments args = Arguments(argc, argv);

	if (args.error)
		return 1;
}
