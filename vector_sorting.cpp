#include <iostream>
#include <vector>
#define INT_MIN (-2147483647 - 1)

using namespace std;

vector<vector<int>> func(vector<vector<int>> teams) {
    vector<vector<int>> result;
    vector<vector<int>> highest_sum_teams;
    vector<vector<int>> final_team;

    int team_number = 1;
    for (const auto& team : teams) {
        int sum = 0;
        int max_value = INT_MIN;
        for (int member : team) {
            sum += member;
            max_value = max(max_value, member);
        }
        result.push_back({team_number, sum, max_value});
        team_number++;
    }

    int max_sum = INT_MIN;
    int max_value = INT_MIN;

    // Find the maximum sum
    for (const auto& team : result) {
        max_sum = max(max_sum, team[1]);
    }

    // Filter teams with the maximum sum
    for (const auto& team : result) {
        if (team[1] == max_sum) {
            highest_sum_teams.push_back(team);
        }
    }

    // If only one team has the highest sum
    if (highest_sum_teams.size() == 1) {
        final_team.push_back(highest_sum_teams[0]);
    } else {
        // Find the maximum max_value among the teams with the highest sum
        for (const auto& team : highest_sum_teams) {
            max_value = max(max_value, team[2]);
        }

        // Filter teams with the highest max_value
        for (const auto& team : highest_sum_teams) {
            if (team[2] == max_value) {
                final_team.push_back(team);
            }
        }
    }

    return final_team;
}

int main() {
    // initial code 
    vector<vector<int>> teams;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int team_size;
        cin >> team_size;
        vector<int> team(team_size);
        for (int j = 0; j < team_size; j++) {
            cin >> team[j];
        }
        teams.push_back(team);
    }
    // you have to implement the func() only
    vector<vector<int>> result = func(teams);

    // print the result(please don't modify this)
    for(int i = 0; i < result.size(); i++) {
        if(i == result.size() - 1) {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2];
        } else {
            cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        }
    }   
    // end of initial code
    return 0;
}
