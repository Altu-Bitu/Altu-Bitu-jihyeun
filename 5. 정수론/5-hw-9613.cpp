#include <iostream>
#include <vector>

using namespace std;

// ���� ���� n���� �־����� ��, ������ ��� ���� gcd�� �� ���ϱ�
// �����ߴ� idea : combination �̿��ؼ� ���� �� �����ؼ� ���ϱ�..?  

//��Ŭ���� ȣ����
int gcd(int a, int b) { // �ִ����� ���ϴ� �Լ�   
    if (b == 0) // ��ǻ� �������� 
        return a;
    return gcd(b, a % b);
}

//������ ��� ���� �ִ������� �� ���ϴ� �Լ�
long long gcdSum(int n, vector<int> &v) { // �迭�� �޴� �Լ�   
    long long ans = 0;

    //������ ��� ���� �ִ����� ���� �� ans �� ���ϱ�
    //���� comnination ������� �ʾƵ� �ݺ�������! 
    for (int i = 0; i < n; i++) { // �ݺ������� �� Ȯ���ؼ� ���� ����   
        for (int j = i + 1; j < n; j++) { // +1�� �����ν� �ߺ��� ���� 
            int g = gcd(max(v[i], v[j]), min(v[i], v[j])); // �տ��� �� �� ū��, �ڿ��� �� �� ���� ��  
            ans += g; // �� ���ؼ� ������ �����  
        }
    }

    return ans; // ���� ����  
}

/**
 * GCD �� ����
 * ������ ��� ���� GCD�� �� ���ϱ�
 * n�� �ִ� 100�̰�, �Է� ���� �ִ� 1,000,000 �̹Ƿ� ������ ���� ���� ū ���� C(100,2) * 1,000,000 = 4,950,000,000
 * ���� ������ long long ������ �ؾ���
 */

int main() {
    int t, n;

    //�Է�
    cin >> t;

    //�Է� + ����
    while (t--) {
        cin >> n;

        vector<int> v(n, 0); //�̷��� �����ϴ� vector�� ����...?  
        for (int i = 0; i < n; i++) {
            cin >> v[i]; // ���� �� �Է�  
        }

        //���
        cout << gcdSum(n, v) << '\n';
    }
    return 0;
}
