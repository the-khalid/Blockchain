#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();
    uint32_t nDifficulty;

    void AddBlock(Block bNew);

private:
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};

#endif