#include <stdio.h>
#include <getopt.h>
#include <string.h>

#include "include/args.h"
#include "include/utils.h"

int parseArgs(int argc, char *argv[], int *a, int *f, int *d) {
    int arg;

    while ((arg = getopt(argc, argv, ":ha:f:d:")) != -1) {
        switch (arg) {
            case 'a':
                if (!strcmp(optarg, "qsort")) *a = QSORT;
                else if (!strcmp(optarg, "odd-even")) *a = ODD_EVEN_SORT;
                else if (!strcmp(optarg, "double-selection")) {
                    *a = DOUBLE_SELECTION_SORT;
                }
                else {
                    printErrorMsg("Algorithm %s is not supported, supported: "
                                  "qsort, odd-even, double-selection\n", optarg);
                    return 1;
                }
                break;
            case 'f':
                if (!strcmp(optarg, "name")) *f = NAME;
                else if (!strcmp(optarg, "group")) *f = GROUP;
                else if (!strcmp(optarg, "score")) *f = SCORE;
                else {
                    printErrorMsg("Field %s doesn't exists,"
                                  "exists: name, group, score\n", optarg);
                    return 1;
                }
                break;
            case 'd':
                if (!strcmp(optarg, "increase")) *d = INCREASE;
                else if (!strcmp(optarg, "decrease")) *d = DECREASE;
                else {
                    printErrorMsg("Option %s isn't available,"
                                  "available: increase, decrease\n", optarg);
                    return 1;
                }
                break;
            case 'h':
                return -1;
            case '?':
                printErrorMsg("Unknown option argument: -%c\n", optopt);
            default:
                break;
        }
    }

    return 0;
}

void printArgsHelp() {
    printf("Arguments:\n");
    printf("   -a <algorithm>\t\tUse <algorithm> to sort array (default: qsort)\n");
    printf("   -f <field>\t\t\tSort array by <field> (default: name)\n");
    printf("   -d <direction>\t\tSort array by <direction> (default: increase)\n");
    printf("   -h\t\t\t\tPrint help (this message) and exit\n");
}