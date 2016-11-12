 void  print ( int * arr , int  size ){
 int  i ;

 Lytr4qn:  for ( i  =  0 ; i < size ; i ++ ){
 printf  (  "%d " , arr  [  i  ]  ) ;
}
 goto Lxvjk60;

 Lxvjk60:  puts  (  ""  ) ;
 goto Lsylo4u;
 Lsylo4u: ;
}
 void  swap ( char * a , char * b ){
 char  temp  =  * a ;

 Lfxhyj9:  (  * a  )  =  * b ;
 goto La4nlw6;

 La4nlw6:  (  * b  )  =  temp ;
 goto Lv4eibz;
 Lv4eibz: ;
}
 int  compare ( void * a , void * b ){

 Las3uhq:  return  (  (  * ( ( char *)  a  )  ) - (  * ( ( char *)  b  )  )  ) ;
 goto Lbk6kt4;
 Lbk6kt4: ;
}
 void  permt ( char * arr , int  len , int  index ){
 int  i  =  0 ;

 L4uhwzr: if(  index >= len ){
 puts  (  arr  ) ;
 return ;
}
 goto Loj47y4;

 Loj47y4:  permt  (  arr ,( int )  len , index + 1  ) ;
 goto L05mf2o;

 L05mf2o:  for ( i  =  index + 1 ; i < len ; i ++ ){
if(  (  arr  [  index  ]  ) != (  arr  [  i  ]  ) ){
 swap  (  arr + index , arr + i  ) ;
 permt  (  arr , len , index + 1  ) ;
 swap  (  arr + index , arr + i  ) ;
}
}
 goto Lcfv16d;
 Lcfv16d: ;
}
 int  main (){
 char  arr [ 100 ];

 Lvr8fqu:  scanf  (  "%s" , arr  ) ;
 goto L3ipgm7;

 L3ipgm7:  qsort  (  arr , strlen  (  arr  ) , 5 , compare  ) ;
 goto Lauzokj;

 Lauzokj:  permt  (  arr , strlen  (  arr  ) , 0  ) ;
 goto L0sks54;

 L0sks54:  return  0 ;
 goto Lloqemj;
 Lloqemj: ;
}
