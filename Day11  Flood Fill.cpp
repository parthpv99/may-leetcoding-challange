/* An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:

	Input: image = [[1,1,1],[1,1,0],[1,0,1]],sr = 1, sc = 1, newColor = 2

	Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation: 
	From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored with the new color. Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

Note:

-> The length of image and image[0] will be in the range [1, 50].
-> The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
-> The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

/* It is similar algorithm to flood fill algorithm in Computer Graphics but here we have to set boundarys manually with the vector positions.
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
            flood(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    
    void flood(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if(image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
            
            //We have to set boundaries so it can not overflow
            if(sr+1<image.size())
                flood(image,sr+1,sc,oldColor,newColor);
            if(sr>0)
                flood(image,sr-1,sc,oldColor,newColor);
            if(sc+1<image[0].size())
                flood(image,sr,sc+1,oldColor,newColor);
            if(sc>0)
                flood(image,sr,sc-1,oldColor,newColor);
        }
    }
};