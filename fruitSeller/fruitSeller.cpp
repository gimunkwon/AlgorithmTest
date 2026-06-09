#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) 
{
    int answer = 0;
    vector<int> box;
    
    sort(score.begin(), score.end(),greater<>());
    
    int count = 0;
    
    for(int i = 0; i < score.size(); i++)
    {
        box.push_back(score[i]);
        count++;
        
        if(count >= m)
        {
            answer += *min_element(box.begin(),box.end()) * m;
            count = 0;
            box.clear();
        }
    }
    
    
    return answer;
}

int main()
{
    solution(4, 3, {4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2});
}