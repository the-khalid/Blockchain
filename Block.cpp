#include "Block.h"
#include "sha256.h"
#include <ctime>
#include <bits/stdc++.h>

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    _nNonce = 0;
    _tTime = time(nullptr);

    sHash = _CalculateHash();
}

void Block::MineBlock(uint32_t nDifficulty)
{
    std::cout << std::fixed;
    clock_t start, end;
    string str;
    start = clock();
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        str += char(0+'0');
    }
    do
    {
        _nNonce++;
        sHash = _CalculateHash();
    }
    while (sHash.substr(0, nDifficulty) != str);
    end = clock();
    cout << "Block mined: " << sHash;
    float time_taken = float(end - start) / float(CLOCKS_PER_SEC);
    cout.precision(3);
    cout << "\nTime elapsed: " << time_taken << "sec" <<  "\n\n";
}

inline string Block::_CalculateHash() const
{
    stringstream ss;
    ss << _nIndex << sPrevHash << _tTime << _sData << _nNonce;

    return sha256(ss.str());
}