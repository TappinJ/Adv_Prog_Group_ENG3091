#include <iostream>
#include "dataset_struct.h"

int main(){

    // 1 Instance
    data_generator my_gen;

    std::cout << "Generating datasets...\n";

    // 2 Calling functions
    my_gen.slr_generator();
    my_gen.mlr_generator();

    std::cout << "Complete!\n";

    return 0;
}