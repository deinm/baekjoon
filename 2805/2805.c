#include <stdio.h>
 
int n,m;
int tree[1000001];
 
long long calc(int height)//높이가 height일때 가져갈수있는 총 나무 양
{
    long long rtn = 0;
    for(int i=1;i<=n;i++)
    {
        if(height<tree[i]) rtn+=tree[i]-height;
    }
    return rtn;
}
 
int main()
{
    int mx=0;
    scanf("%d %d",&n,&m);
 
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tree[i]);
        if(mx < tree[i]) mx=tree[i];
    }
 
    int l=0, r=mx;
    //left를 의미하는 l과 right를 의미하는 r
    //0~mx의 정렬에서 l은 0 r은 mx로 초기화
 
    int mid,ans=0;//mid는 r과 l의 중간값
 
    long long int tmp;
 
    //Binary Search의 모범 코드
    while(l<r)//left와 right가 같아질때까지
    {
        mid = (l+r)/2;
 
        tmp = calc(mid);//설정한 높이가 중간값일때 가져갈수있는 나무의 양
        if(tmp<m)//나무의 양이 m보다 작을때
        {
            //mid보다 큰값일때는 언제나 나무의 양이 부족하므로
            //나무의 양을 늘리기 위해 mid보다 작게 설정
            r=mid;
        }
        else //나무의 양이 m보다 같거나 많을때
        {
            ans = mid;//현재 설정가능한 높이의 최댓값
            l=mid+1;//mid보다 클때도 설정가능한 높이가 있는지 판별하기 위해
        }
    }
 
    printf("%d",ans);
    return 0;
}
