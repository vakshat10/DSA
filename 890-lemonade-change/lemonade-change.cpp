class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int n = bills.size();

        int five = 0,ten = 0; // no use of 20 as a change

        for(int bill : bills){

            if (bill == 5){
                five++;
            }

            else if(bill == 10){
                if(five>0){
                    five--;
                    ten++;
                }

                else{
                    return false;
                }
            }

            else{     // bill is 20
                 
                 if(ten>0 && five>0){   // GREEDY APPROACH
                     ten--;
                     five--;
                 }

                 else if(five>=3){
                    five = five - 3;
                 }

                 else{
                    return false;
                 }

            }
        }
        return true;
        
        
    }
};