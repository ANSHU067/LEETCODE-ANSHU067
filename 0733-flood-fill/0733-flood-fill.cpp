class Solution {
public:
void floo(vector<vector<int>>& image, int i, int j, int color,int old){
    if(i<0||j<0||i>=image.size()||j>=image[0].size()||image[i][j]!=old||image[i][j]==color){
        return ;
    }
    image[i][j]=color;
    floo(image,i-1,j,color,old);
    floo(image,i,j+1,color,old);
    floo(image,i+1,j,color,old);
    floo(image,i,j-1,color,old);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        floo(image,sr,sc,color,image[sr][sc]);
        return image;
        
    }
};