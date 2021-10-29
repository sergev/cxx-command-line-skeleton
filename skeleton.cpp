/*
 * Skeleton for a generic C++ program.
 *
 * Created by Serge Vakulenko.
 * This code is in public domain.
 * You may do whatever you wish with it, but please don't blaim me for any issues. :)
 */
#include <getopt.h>
#include <cstdlib>
#include <iostream>

//
// Remember the program name.
//
static const char *prog_name;

//
// Print usage message and exit with given status.
//
void usage(int exit_status)
{
    std::cerr << "C++ Skeleton, Version " VERSION << std::endl;
    std::cerr << "Usage:" << std::endl;
    std::cerr << "    " << prog_name << " [-v] [-r count] filename..." << std::endl;
    std::cerr << "Options:" << std::endl;
    std::cerr << "    -v  or  --verbose         Verbose mode" << std::endl;
    std::cerr << "    -r #  or --repeat=#       Repeat count, default 1" << std::endl;
    std::cerr << "    -V  or  --version         Print version and exit" << std::endl;
    std::cerr << "    -h  or  --help            Print this message" << std::endl;
    exit(exit_status);
}

int main(int argc, char **argv)
{
    int exit_status = EXIT_SUCCESS;

    // Default values of parameters.
    bool verbose = false;
    int repeat_count = 1;

    // Options.
    const struct option long_options[] = {
        // clang-format off
        { "help",       no_argument,        nullptr,    'h' },
        { "version",    no_argument,        nullptr,    'V' },
        { "verbose",    no_argument,        nullptr,    'v' },
        { "repeat",     required_argument,  nullptr,    'r' },
        { nullptr,      no_argument,        nullptr,    '\0' },
        // clang-format on
    };

    // Get program name for later use.
    prog_name = argv[0];

    // Parse command line options.
    for (;;) {
        switch (getopt_long(argc, argv, "vVhr:", long_options, nullptr)) {
        case EOF:
            break;
        case 0:
            continue;
        case 'v':
            // Verbose.
            verbose = true;
            continue;
        case 'r':
            // Repeat count.
            try {
                repeat_count = std::stoull(optarg);
            } catch (...) {
                std::cerr << "Bad --repeat option: " << optarg << std::endl;
                usage(EXIT_FAILURE);
            }
            continue;
        case 'V':
            // Show version and exit.
            std::cout << "C++ Skeleton, Version " VERSION << std::endl;
            exit(EXIT_SUCCESS);
        case 'h':
            // Show usage message and exit.
            usage(EXIT_SUCCESS);
            continue;
        default:
            usage(EXIT_FAILURE);
        }
        break;
    }
    argc -= optind;
    argv += optind;

    // Must specify at least one filename.
    if (argc == 0) {
        usage(EXIT_SUCCESS);
    }
    for (int i = 0; i < argc; i++) {
        const char *filename = argv[i];
        try {
            // Process one file.
            // TODO: Insert your code here.
            std::cout << "Filename: " << filename << std::endl;

        } catch (std::exception &ex) {
            // Something bad happened.
            // Print error message.
            std::cerr << filename << ": ERROR: " << ex.what() << std::endl;
            exit_status = EXIT_FAILURE;
        }
    }
    exit(exit_status);
}
