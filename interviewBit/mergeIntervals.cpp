//Given a collection of intervals, merge all overlapping intervals.
//For example:
//Given [1,3],[2,6],[8,10],[15,18],
//return [1,6],[8,10],[15,18].
//Make sure the returned intervals are sorted.    
//-----------------------------------------------------------------//
#include <bits/stdc++.h>

using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

bool compare(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &A, Interval newInterval){
	vector<Interval> copy;
	for(int i = 0; i < A.size(); i++){
		copy.push_back(Interval(A[i].start, A[i].end));
	}
	copy.push_back(Interval(newInterval.start, newInterval.end));

	sort(copy.begin(), copy.end(), compare);

	int j = 0;
	for(int i = 1; i <= copy.size(); i++){
		if(copy[j].end >= copy[i].start){
			copy[j].end = max(copy[j].end, copy[i].end);
			//i++;
		}else{
			++j;
			copy[j].start = copy[i].start;
			copy[j].end = copy[i].end;
		}
	}
	copy.erase(copy.begin()+j+1, copy.end());
	return copy;

}

int main(){

	vector<Interval> v;
	int n;
	cin >> n;
	int x, y;
	for(int i = 0; i < n; i++){
		cin >> x;
		cin >> y;
		v.push_back(Interval(x,y));
	}

	Interval new_(Interval(22412508, 55842029));


	vector<Interval> res = merge(v, new_);

	cout << "result size: " << res.size() << endl;
	for(int i = 0; i < res.size(); i++)
		cout << res[i].start << " " << res[i].end << endl;
	return 0;
 }