#include "Blockchain.h"

int main()
{
    Blockchain bChain = Blockchain();

    int n=0, d=0;
    cout << "How many Blocks do you wanna mine, miner?" << "\t";
    cin >> n;
    cout << "Set Difficulty level:" << "\t";
    cin >> d;
    bChain.nDifficulty = d;

    for(int i=1; i<=n; i++)
    {
        cout << "Mining block "<< i << endl;   
        string str = "Data of Block " + char(0+'i');
        Block bBlock = Block(1, str);
        bChain.AddBlock(bBlock);
    }

    return 0;
}