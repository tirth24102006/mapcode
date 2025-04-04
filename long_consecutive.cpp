class Solution {
    public:
         int findmaxlength(unordered_map<int,bool>& map,int key){
            int length=0;
            while(map.find(key)!=map.end()){
                key++;
                length++;
            }
            return length;
         }
        int longestConsecutive(vector<int>& nums) {
            unordered_map<int,bool>map;
            for(int i =0;i<nums.size();i++){
                map[nums[i]]=true;
            }
            for(int i =0;i<nums.size();i++){
               if(map.find(nums[i]-1)!=map.end()){
                map[nums[i]]=false;
               }
            }
            int max=0;
            for(auto ele:map){
                int v =ele.first;
                if(ele.second==true){
                  max=std:: max(max,findmaxlength(map,v));
                }
                
            }
           
          return max;
        }
    };
