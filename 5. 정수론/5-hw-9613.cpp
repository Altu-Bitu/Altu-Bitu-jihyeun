#include <iostream>
#include <vector>

using namespace std;

// 양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 gcd의 합 구하기
// 생각했던 idea : combination 이용해서 나온 값 축적해서 더하기..?  

//유클리드 호제법
int gcd(int a, int b) { // 최대공약수 구하는 함수   
    if (b == 0) // 사실상 종료조건 
        return a;
    return gcd(b, a % b);
}

//가능한 모든 쌍의 최대공약수의 합 구하는 함수
long long gcdSum(int n, vector<int> &v) { // 배열을 받는 함수   
    long long ans = 0;

    //가능한 모든 쌍의 최대공약수 구한 후 ans 에 더하기
    //굳이 comnination 사용하지 않아도 반복문으로! 
    for (int i = 0; i < n; i++) { // 반복문으로 다 확인해서 쌍을 생성   
        for (int j = i + 1; j < n; j++) { // +1을 함으로써 중복을 막음 
            int g = gcd(max(v[i], v[j]), min(v[i], v[j])); // 앞에는 쌍 중 큰수, 뒤에는 쌍 중 작은 수  
            ans += g; // 다 더해서 합으로 만든다  
        }
    }

    return ans; // 합을 리턴  
}

/**
 * GCD 합 문제
 * 가능한 모든 쌍의 GCD의 합 구하기
 * n이 최대 100이고, 입력 수가 최대 1,000,000 이므로 가능한 합의 가장 큰 경우는 C(100,2) * 1,000,000 = 4,950,000,000
 * 따라서 정답을 long long 범위로 해야함
 */

int main() {
    int t, n;

    //입력
    cin >> t;

    //입력 + 연산
    while (t--) {
        cin >> n;

        vector<int> v(n, 0); //이렇게 선언하는 vector는 뭐지...?  
        for (int i = 0; i < n; i++) {
            cin >> v[i]; // 먼저 쌍 입력  
        }

        //출력
        cout << gcdSum(n, v) << '\n';
    }
    return 0;
}
