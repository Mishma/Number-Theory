    #include<bits/stdc++.h>
    using namespace std;
    float n;
    float rootF(float high, float low)
    {
        float mid = (high+low)/2;
        if(high-low < 0.001) {
                cout<<mid<<endl;
                return mid;
        }
      //  cout<<high<<' '<<low<<endl;
        if(mid*mid > n){
            high = mid;
            rootF(high, low);
        }
        else{
            low = mid;
            rootF(high, low);
        }
    }
    int main()
    {

        while(cin>>n)
        {
            float root = rootF(n, 0.0);
            cout<<root<<endl;
        }
        return 0;
    }

