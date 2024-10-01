//
// Created by mrhax on 9/22/24.
//

#include "Block.hpp"
#include <iostream>
#include <sstream>
#include "../libs/sha256.hpp"

#include <thread>
#include <utility>
#include <vector>


Block::Block(const uint32_t nIndexIn, std::string sDataIn) : _nIndex(nIndexIn), _sData(std::move(sDataIn)) {
    _nNonce = -1;
    // _tTime = time(nullptr); //TODO replace for real-time use
    _tTime = 1727481184;
}

std::string Block::GetHash() const {
    return this->sHash;
}

void Block::MineBlock(const uint32_t nDifficulty) {
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    const std::string str(cstr);

    std::vector<std::thread> threads;

    uint32_t nonce = _nNonce;

    while (true) {
        nonce ++;
        std::string hash = _CalculateHashWithNonce(nonce);

        // Check if we've found a valid hash
        if (hash.substr(0, nDifficulty) == str) {
            _nNonce = nonce;
            sHash = hash;
            std::cout << "Block mined--> time:" << _tTime <<std::endl;
            std::cout << "prevHash:" << sPrevHash << std::endl;
            std::cout << "nonce:" << _nNonce << " hash:" << sHash << std::endl;
            break;
        }
    }
}

std::string Block::_CalculateHashWithNonce(const uint32_t nonce) const {
    std::stringstream ss;

    //Aca, el nonce es insertado como bytes directos. Si desean usar el nonce como un string,
    // cambiar las lineas siguientes

    //Nonce como string
    // ss << _nIndex  << "\n" << _tTime  << "\n" << sPrevHash << "\n" << _sData << "\n" << nonce;

    //Nonce como bytes directos
    ss << _nIndex  << "\n" << _tTime  << "\n" << sPrevHash << "\n" << _sData << "\n";
    ss.write(reinterpret_cast<const char*>(&nonce), sizeof(nonce));


    return sha256(ss.str());
}