import syntaxtree.*;
import visitor.*;
import java.io.PrintWriter;

public class ParserMain {
   public static void main(String [] args) {
      try {
         Node root = new CParser(System.in).Goal();
         // System.out.println("Program parsed successfully");
         UsedIdsGen u = new UsedIdsGen();
         root.accept(u);
         Translator t = new Translator();
         t.used = u.used;
         root.accept(t);

         try{
          PrintWriter writer = new PrintWriter("../tmp/count", "UTF-8");
          writer.println(Integer.toString(u.maxNestingDepth));
          writer.close();          
         }
         catch(Exception e){
           System.out.println(e.toString());
         }
      }
      catch (ParseException e) {
         System.out.println(e.toString());
      }
   }
} 


