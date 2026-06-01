#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    vector<int> answer;
    
    vector<vector<int>> Ranking(score.size());
    
    int limits = min(k, (int)score.size());
    for (int i = 0; i < limits; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            Ranking[i].push_back(score[j]);
        }
        sort(Ranking[i].begin(), Ranking[i].end());
    }
    
    for (int i = k; i < score.size(); i++)
    {
        Ranking[i] = Ranking[i - 1];
        Ranking[i][0] = max(Ranking[i][0], score[i]);
        sort(Ranking[i].begin(),Ranking[i].end());
    }
    
    for (int i = 0; i < Ranking.size(); i++)
    {
        answer.push_back(Ranking[i][0]);
    }
    
    return answer;
}

int main()
{
    solution(4,{0, 300, 40, 300, 20, 70, 150, 50, 500, 1000});
}