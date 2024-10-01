//
// Created by mrhax on 9/22/24.
//

#ifndef BLOCK_H
#define BLOCK_H
#include <cstdint>
#include <string>



class Block {
public:
    std::string sPrevHash;
    std::string sHash;
    Block(uint32_t nIndexIn, std::string sDataIn);
    std::string GetHash() const;
    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    std::string _sData;
    time_t _tTime;

    std::string _CalculateHashWithNonce(uint32_t nonce) const;

};



#endif //BLOCK_H
