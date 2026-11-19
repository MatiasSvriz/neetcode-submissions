class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int numberOfRemoved = 0;
        int lastEnd = intervals[0][1];

        // Empezamos por el intervalo segundo
        // Dado que en lastEnd ya consideramos el primer intervalo
        for(int i = 1; i < intervals.size(); i++){

            if(intervals[i][0] < lastEnd){

                numberOfRemoved ++;
                lastEnd = min(lastEnd, intervals[i][1]);

            }else{

                lastEnd = intervals[i][1];

            }

        }

        return numberOfRemoved;

    }
};
