#ifndef NOTE
#define NOTE


//code bank...
//      string temp = string(line.substr(0, line.find_first_of(" ")));
//      cout<<"testing temp: "<<temp<<endl;
//      //number .... and negative
//      //if(strspn( temp.c_str(), "-.0123456789" ) == temp.size()){
//      //    cout<<"temp: "<<temp<<endl;
//      //}else{
//      //while(strspn( temp.c_str(), "-.0123456789" ) != temp.size())
//          run(temp[0], temp);
//      //}
//      //check if it is negative
//      //check if it is dobule
//      //conver to fraction
//      line = line.substr(line.find_first_of(" ") + 1, line.size()-1);
//      cout<<"testing: "<<line<<endl;

//bool isNeg = (other<0)?true:false;
//double  d = (isNeg)?other*-1.0:other; // just a random double
//char*   bits = (char*)&d; // access my double byte-by-byte
//int     array[64]; // result
////http://stackoverflow.com/questions/14109923/converting-double-to-array-of-bits-for-genetic-algorithm-in-c
//for (int i = 0, k = 63; i < 8; ++i) // for each byte of my double
//    for (char j = 0; j < 8; ++j, --k) // for each bit of each byte of my double
//        array[k] = (bits[i] >> j) & 1;
//int base = 2;
////http://mathforum.org/library/drmath/view/56091.html
//fraction re(0, 1);
//for(int i=0; i<64; i++){
//   if(array[i]==1){
//       fraction temp = fraction(1, base);
//       re = re + temp;
//    }
//   base*=2;
//}
//int denom2 = re.getDenom();
//int num2 = re.getNume();
#endif // NOTE

