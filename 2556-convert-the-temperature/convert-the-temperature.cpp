class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double>arr;
        double Kelvin=celsius+273.15;
        double Fahrenheit=celsius*1.80+32.00;
        arr.push_back(Kelvin);
        arr.push_back(Fahrenheit);
        return arr;


        
    }
};