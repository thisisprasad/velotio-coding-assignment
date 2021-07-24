/**
    Question: Write a function takes the time in digital format(9:15, 7:37 etc) and returns the 
    angle b/w the minute and the hour hand. It should return the smaller angle.

    Solution: Whenever the minute hand changes by a minute, the hour hand changes by 0.5 degrees.
              This case is also handled.
*/

#include<bits/stdc++.h>

using namespace std;

const float oneHourDegree = 30;
const float oneMinuteDegree = 6;
const float oneMinuteToHourDegree = 0.5;

vector<int> timeSplit(string digTime, char delimiter) {
    vector<int> timeVector;
    string str = "";
    for(auto it: digTime) {
        if(it == delimiter) {
            timeVector.push_back(stoi(str));
            str = "";
        } else {
            str += it;
        }
    }
    if(str.size() > 0) {
        timeVector.push_back(stoi(str));
    }

    return timeVector;
} 

vector<int> getInput() {
    cout<<"Enter time: ";
    string digitalTime;
    cin>>digitalTime;
    vector<int> numericTime = timeSplit(digitalTime, ':');
    return numericTime;
}

void solve(float hour, float minute) {
    float minuteDegree = minute*oneMinuteDegree;
    float hourDegree = hour*oneHourDegree + minute*oneMinuteToHourDegree;
    float angle1 = abs(hourDegree - minuteDegree);
    float angle2 = abs((360 - hourDegree) + minuteDegree);

    cout<<"Angle between the minute and the hour hand: "<<min(angle1, angle2)<<" degrees."<<endl;
}

int main() {
    vector<int> numericTime = getInput();
    solve((float)numericTime[0], (float)numericTime[1]);
    return 0;
}