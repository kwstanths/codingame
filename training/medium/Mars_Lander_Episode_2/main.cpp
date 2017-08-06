#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define SURFACE 30


int main()
{
    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();

    int land[SURFACE][2];
    
    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY; cin.ignore();
        land[i][0] = landX;
        land[i][1] = landY;
    }

    int landing_x, landing_y;
    for(int i=0; i<surfaceN-1; i++){
        if(land[i][1] - land[i+1][1] == 0){
            landing_x = (land[i][0] + land[i+1][0]) /2;
            landing_y = land[i][1];
        }
    }
    
    
    cerr << landing_x << " " << landing_y << endl;
    // Find the maximum height
    int maxHeight = 0;
    for (int i = 0; i < surfaceN; ++i)
        maxHeight = max(maxHeight, land[i][1]);
        
    // game loop
    while (1) {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();


        
        if (X < landing_x - 400) {
            cerr << "minus" << endl;
            maxHeight = landing_y;
            for (int i = 0; i < surfaceN; ++i) {
                if ((land[i][0] < landing_x - 400) && (land[i][0] > X))
                    maxHeight = max(maxHeight, land[i][1]);
            }
             
            if (hSpeed <= -20) rotate = -30;
            else if (hSpeed < 20) rotate = -20;
            else if (hSpeed >= 20) rotate = 30;
            
            if (Y + 10*vSpeed < Y - landing_y) power = 4;
            else power = min(max(-vSpeed - 36, 0), 4);
            
            if ((Y - vSpeed*vSpeed <= maxHeight) && (X < landing_x - 1000)) {
                power = 4;
                rotate = min(max(rotate, -3), 3);
            }
        } else if (X > landing_x + 400) {
            cerr << "plus" << endl;
            maxHeight = landing_y;
            for (int i = 0; i < surfaceN; ++i) {
                if ((land[i][0] > landing_x + 400) && (land[i][0] < X))
                    maxHeight = max(maxHeight, land[i][1]);
            }
            
            if (hSpeed <= -20) rotate = -30;
            else if (hSpeed < 20) rotate = 20;
            else if (hSpeed >= 20) rotate = 30;

            if ((vSpeed < 0) && (10*vSpeed < Y - landing_y)) power = 4;
            else power = min(max(-vSpeed - 36, 0), 4);

            if ((Y - vSpeed*vSpeed <= maxHeight) && (X > landing_x + 1000)) {
                power = 4;
                rotate = min(max(rotate, -3), 3);
            }
        } else {
            cerr << "inside" << endl;
            rotate = min(max((int)(hSpeed / 30.0 * 45.0), -90), 90);
            power = min(max(-vSpeed - 30, max(abs((int)((rotate/45.0)*4)), 0)), 4);
        }
        
        if (Y - landing_y <= ((abs(2*rotate / 15) + 1) * -vSpeed)) rotate = 0;

        if (((rotate / 15) + 1) * power >= fuel) rotate = 0;
        
        cout << rotate << " " << power << endl;
    }
    
}
