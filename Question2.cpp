/**
    Question: Your company is downsizing. They are letting go of the redundant employees and need to 
    calculate the total severance amount. Company has a policy to give a severance of 1 lakh rupees 
    to every employee it lets go. Now every employee has a capability which is defined by a 
    number, let's say 2. This means that this employee can do 2 units of work in a day. All the employees 
    in the company have different capabilities. Redundancy it judged by the company on the basis if an 
    employee with a lower capability can do the work of an employee with higher capability given 
    unlimited amount of time. So, if E1 has a capability of 2 and E2 has the capability of 8 then E2 is 
    redundant as E1 can do his/her job in 4 days. Company has 1000 employees. It has hired in such a 
    way that it can handle any assignment that has less than 1200 units of work and hasn't hired any 
    employee with over 1200 capability. Now with the above information, you are given the list with 
    1000 employees: [2, 6, 8, 9, 12…] with numbers representing their capabilities. This list is also 
    sorted with increasing capability.  Write a function that calculates the total severance amount 
    to be handed out by the company

    Solution: Binary-search. Time complexity - O(nlogn)
*/

#include<bits/stdc++.h>

using namespace std;

const int thresholdTask = 1200;
const int employeeCount = 1000;

vector<int> getInput() {
    vector<int> emp;
    cout<<"Enter employee capabilities in a space-separated format: ";
    for(int i = 0; i < employeeCount; i++) {
        int x; cin>>x;
        emp.push_back(x);
    }

    return emp;
}

bool canCompleteThresholdTask(vector<int>& employeeCapability, int pos, int thresholdTask) {
    int sum = 0;
    for(int i = 0; i <= pos; i++) {
        sum += employeeCapability[i];
    }

    return (sum >= thresholdTask);
}

void solve(vector<int> employeeCapability) {
    int n = employeeCapability.size();
    int lo = 0, hi = n-1;
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        if(canCompleteThresholdTask(employeeCapability, mid, thresholdTask)) {
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    int severance = (n-1) - lo;
    cout<<"Severance cost: " << severance<<" lakhs rupees."<<endl;
}

int main() {
    vector<int> employeeCapability = getInput();
    solve(employeeCapability);

    return 0;
}