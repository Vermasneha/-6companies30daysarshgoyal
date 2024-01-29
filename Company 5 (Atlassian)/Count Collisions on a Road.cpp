class Solution {
public:
    int countCollisions(string directions) {
        int i, len = directions.length();
        vector<char> stack;

        int ans = 0;
        for(i = len - 1; i >= 0; i--){
            if(stack.empty() || directions[i] == 'L'){
                stack.push_back(directions[i]);
            }
            else{
                if(directions[i] == 'S'){
                    while(!stack.empty() && stack.back() == 'L'){
                        stack.pop_back();
                        ans++;
                    }
                    stack.push_back('S');
                }
                else{
                    if(stack.back() == 'S'){
                        ans++;
                    }
                    else if(stack.back() == 'L'){
                        ans += 2;
                        stack.pop_back();
                        while(!stack.empty() && stack.back() == 'L'){
                            stack.pop_back();
                            ans++;
                        }
                        stack.push_back('S');
                    }
                }
            }
        }
        return ans;
    }
};
