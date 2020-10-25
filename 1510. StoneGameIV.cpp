/*

Title: 1510. Stone Game IV

Problem:

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile.  On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n. Return True if and only if Alice wins the game otherwise return False, assuming both players play optimally.


*/



class Solution {
public:
    bool winnerSquareGame(int n) {
        
        vector<int> v(n+1,0);
        
        int done,r,s;
        for(int i = 1; i <= n; i++){
            s = sqrt(i);
            if((s*s) == i){
                v[i] = 1;
                vb[i] = 1;
            }else{
                done = 0;
                for(int j = 1; j*j < i && !done; j++){
                    r = i - (j*j);
                    if(v[r] == 0){
                        done = 1;
                    }
                }
                if(done == 1){
                    v[i] = 1;
                }else{
                    v[i] = 0;
                }               
                
            }
        }
        
        return v[n] == 1;
    }
};
