#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) 
{
    vector<int> month_days = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int total_day = 0;
    for (int i = 1; i < a; i++)
    {
        total_day += month_days[i];
    }
    
    total_day += b;
    
    vector<string> day_of_week = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    
    return day_of_week[total_day % 7];
}

int main()
{
    solution(5, 24);
}