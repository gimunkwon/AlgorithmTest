#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "";
    
    queue<string> queue_cards1;
    queue<string> queue_cards2;
    queue<string> queue_goal;
    
    for (const string& word : cards1)
    {
        queue_cards1.push(word);
    }
    for (const string& word : cards2)
    {
        queue_cards2.push(word);
    }
    for (const string& word : goal)
    {
        queue_goal.push(word);
    }
    
    bool bmake_word = false;

    while (!queue_goal.empty())
    {
        if (!queue_cards1.empty() && queue_goal.front() == queue_cards1.front())
        {
            queue_cards1.pop();
            queue_goal.pop();
        }
        else if (!queue_cards2.empty() && queue_goal.front() == queue_cards2.front())
        {
            queue_cards2.pop();
            queue_goal.pop();
        }
        else
        {
            break;
        }
    }
        
    if (queue_goal.empty())
    {
        bmake_word = true;
    }
    
    if (bmake_word)
    {
        answer = "Yes";
    }
    else
    {
        answer = "No";
    }
    
    return answer;
}

int main()
{
    solution({"i","water","drink"}, {"want", "to"}
        , {"i", "want", "to", "drink", "water"});
}