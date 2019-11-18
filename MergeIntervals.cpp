/*
Merge Overlapping Intervals
Given a collection of intervals, merge all overlapping intervals. 
For example: Given [1,3],[2,6],[8,10],[15,18], return [1,6],[8,10],[15,18]. Make sure the returned intervals are sorted.
*/

// sort using comparator and then if end of one interval is greater then start of next merge them else add the interval to res
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool comp(Interval a, Interval b)
{
    return (a.start < b.start);
}

vector<Interval> Solution::merge(vector<Interval> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(), comp);

    //int idx=0;
    vector<Interval> res;
    res.emplace_back(A[0]);

    for (int i = 1; i < A.size(); i++)
    {
        if (res.back().end >= A[i].start)
        {
            res.back().end = max(res.back().end, A[i].end);
            // res.back().start=min(res.back().start, A[i].start);
        }
        else
        {
            res.emplace_back(A[i]);
            //idx++;
        }
    }
    return res;
}
