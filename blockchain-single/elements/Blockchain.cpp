//
// Created by mrhax on 9/22/24.
//

#include "Blockchain.hpp"

#include <utility>
#include "Block.hpp"


Blockchain::Blockchain(const int difficulty) {
    Block genesis(0, "Genesis Block");
    genesis.sHash = "0";
    _vChain.push_back(genesis);
    _nDifficulty = difficulty;
}


void Blockchain::AddBlock(std::string dataIn) {
    Block bNew(_vChain.size(), std::move(dataIn));
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}

