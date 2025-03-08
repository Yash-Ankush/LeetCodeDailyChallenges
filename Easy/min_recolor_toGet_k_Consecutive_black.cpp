class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mini=k;
        int whiteCount=0;
        
        //The First Loop i to k
        for(int i=0; i<k; i++){
            if(blocks[i]=='W') whiteCount++;
        }
        mini=whiteCount;

        //sliding window for next remaining
        for(int i=k; i<blocks.size(); i++){
            if(blocks[i]=='W') whiteCount++;
            if(blocks[i-k] == 'W') whiteCount--;

            mini=min(mini, whiteCount);
        }

        return mini;

    }
};
