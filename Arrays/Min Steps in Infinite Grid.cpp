Question : You are in an infinite 2D grid where you can move in any of the 8 directions:
x,y) to  (x+1, y), (x - 1, y), (x, y+1), (x, y-1),
 (x-1, y-1), (x+1,y+1), (x-1,y+1), (x+1,y-1)
 You are given a sequence of points and the order in 
which you need to cover the points. Give the minimum number
 of steps in which you can achieve it. You start from the first point.

 Example : Input : [(0, 0), (1, 1), (1, 2)]
           Output : 2
           Input : [(5,20),(15,15)]
           Output : 10
Solution :  order is specified
            find minnimum steps require from current point to next point
            sum of all these minimum steps will be required answer
            min_steps = max(abs(x2-x1),max(y2-y1))
                reason :    One way to reach form a point (x1,y1) to (x2, y2) is to 
                move abs(x2-x1) steps in horizontal direction and abs(y2-y1) steps 
                in vertical direction, but this is not the shortest path to reach (x2,y2). 
                The best way would be to cover the maximum possible distance in diagonal 
                direction and remaining in horizontal or vertical direction. If we look 
                closely this just reduces to maximum of abs(x2-x1) and abs(y2-y1).
Code :
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    if(A.size()==0 || A.size()==1)
    return 0;
    int min_steps = 0;
    
    for(int i=0;i<A.size()-1;i++){
        min_steps += max(abs(A[i+1]-A[i]),abs(B[i+1]-B[i]));
    }
    return min_steps;
}



           
