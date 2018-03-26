#include <stdio.h>
#include <stdlib.h>
#include "Hasher.h"

void parseArguments(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Incorrect arguments. Usage:\n\t./testHash astring\n\nWhere astring a string to get the hash of.\n");
        exit(-1);
    }
}

int main(int argc, char *argv[]) {
    parseArguments(argc, argv);

    Hasher *h = createHasher();
    fprintf(stdout, "%s was hashed to %d\n", argv[1], h->hash(argv[1]));
    cleanup(h);

    return 0;
}
