//
// Created by Jesson on 2021/2/22.
//

#include "threadpool.h"
#include <iostream>

int main(){
    try {
        std::threadpool pool(4);
        std::vector< std::future<int> > results;

        for (int i = 0; i < 8; ++i) {
            results.emplace_back(
                    pool.commit([i] {
                        std::cout << "hello " << i << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(1));
                        std::cout << "world " << i << std::endl;
                        return i*i;
                    })
            );
        }
        std::cout << " ================ " << std::this_thread::get_id() << std::endl;

        for (auto && result : results)
            std::cout << result.get() << ' ';
        std::cout << std::endl;
        return 0;
    }
    catch (std::exception& e) {
        std::cout << "ERROR" << std::this_thread::get_id() << e.what() << std::endl;
    }

}
