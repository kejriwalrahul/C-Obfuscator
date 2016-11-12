 void  print ( int * arr , int  size ){

 Lofonzr:  int  i ;
 goto Lsud8qr;

 Lsud8qr:  for ( i  =  0 ; i < size ; i ++ ){
 printf  (  "%d " , arr  [  i  ]  ) ;
}
 goto Lfw8ex9;

 Lfw8ex9:  puts  (  ""  ) ;
 goto Lyml53q;
 Lyml53q: ;
}
 void  swap ( char * a , char * b ){

 Ldleh0i:  char  temp  =  * a ;
 goto Lkzxszh;

 Lkzxszh:  (  * a  )  =  * b ;
 goto Ll8ekjq;

 Ll8ekjq:  (  * b  )  =  temp ;
 goto Lgdu534;
 Lgdu534: ;
}
 void  permt ( char * arr , int  len , int  index ){

 Lwfgnz0:  int  i  =  0 ;
 goto Ldq0aod;

 Ldq0aod: if(  index >= len )
 Ljz8umg: {
 puts  (  arr  ) ;
 return ;
}
 goto Lm1fmh2;
 goto Ljz8umg;

 Ljz8umg:  permt  (  arr ,( int )  len , index + 1  ) ;
 goto L5f7fne;

 L5f7fne:  for ( i  =  index + 1 ; i < len ; i ++ ){
if(  (  arr  [  index  ]  ) != (  arr  [  i  ]  ) ){
 swap  (  arr + index , arr + i  ) ;
 permt  (  arr , len , index + 1  ) ;
 swap  (  arr + index , arr + i  ) ;
}
}
 goto Lgf7hmn;
 Lgf7hmn: ;
}
 int  main (){

 L2tyfx8:  char  arr [ 100 ];
 goto L9aa63v;

 L9aa63v:  scanf  (  "%s" , arr  ) ;
 goto Ll1fn5k;

 Ll1fn5k:  qsort  (  arr , strlen  (  arr  ) , 5 , compare  ) ;
 goto Lhxbyoz;

 Lhxbyoz:  permt  (  arr , strlen  (  arr  ) , 0  ) ;
 goto Lh5vs0i;

 Lh5vs0i:  return  0 ;
 goto Lhcgwuo;
 Lhcgwuo: ;
}
