//
// Created by mrhax on 9/22/24.
//

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.hpp"

using namespace std;


class Blockchain {
public:
    explicit Blockchain(int difficulty);

    void AddBlock(std::string dataIn);

private:
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};



#endif //BLOCKCHAIN_H
