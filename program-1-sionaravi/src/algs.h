//Siona Ravi
//CSCE 350 - Program 1

#ifndef ALGS_H
#define ALGS_H

#include <algorithm>
#include <queue>
using std::swap;

template<typename T>
void heapsort(std::vector<T>& V){
	std::priority_queue<T> random;

	for (int i=0; i<V.size(); i++){
		random.push(V.at(i));
	}
}

bool are_anagrams(std::string a, std::string b){
	if(a.length() != b.length()) return false;

	int alpha[26] = {0};
	int beta[26] = {0};

	for (int i=0; i<a.length(); i++){
		alpha[a[i] - 65]++;
		beta[b[i] - 65]++;
	}

	for(int i=0; i<26; i++){
		if(alpha [i] != beta [i])
		return false;
	}
	return true;
}

#endif
