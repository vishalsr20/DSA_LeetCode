class Solution {
public:
    void isColor(vector<vector<int>>& image, int sr, int sc, int color , int m , int n,int originalColor){
        if(sr < 0 || sc < 0 || sr >= m || sc >= n){
            return ;
        }
        if(image[sr][sc] != originalColor){
            return;
        }
        image[sr][sc] = color;
        isColor(image,sr-1,sc,color,m,n,originalColor);
        isColor(image,sr+1,sc,color,m,n,originalColor);
        isColor(image,sr,sc-1,color,m,n,originalColor);
        isColor(image,sr,sc+1,color,m,n,originalColor);
       
       


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];
        if(originalColor == color) {
            return image;
        }
        isColor(image , sr,sc,color,m,n,originalColor);
        return image;
        
    }
};