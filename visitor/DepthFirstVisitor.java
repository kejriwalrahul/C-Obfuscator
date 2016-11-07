//
// Generated by JTB 1.3.2
//

package visitor;
import syntaxtree.*;
import java.util.*;

/**
 * Provides default methods which visit each node in the tree in depth-first
 * order.  Your visitors may extend this class.
 */
public class DepthFirstVisitor implements Visitor {
   //
   // Auto class visitors--probably don't need to be overridden.
   //
   public void visit(NodeList n) {
      for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); )
         e.nextElement().accept(this);
   }

   public void visit(NodeListOptional n) {
      if ( n.present() )
         for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); )
            e.nextElement().accept(this);
   }

   public void visit(NodeOptional n) {
      if ( n.present() )
         n.node.accept(this);
   }

   public void visit(NodeSequence n) {
      for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); )
         e.nextElement().accept(this);
   }

   public void visit(NodeToken n) { }

   //
   // User-generated visitor methods below
   //

   /**
    * f0 -> ( ExternalDeclaration() )+
    */
   public void visit(TranslationUnit n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( FunctionDefinition() | Declaration() )
    */
   public void visit(ExternalDeclaration n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> [ DeclarationSpecifiers() ]
    * f1 -> Declarator()
    * f2 -> [ DeclarationList() ]
    * f3 -> CompoundStatement()
    */
   public void visit(FunctionDefinition n) {
      n.f0.accept(this);
      n.f1.accept(this);
      n.f2.accept(this);
      n.f3.accept(this);
   }

   /**
    * f0 -> DeclarationSpecifiers()
    * f1 -> [ InitDeclaratorList() ]
    * f2 -> ";"
    */
   public void visit(Declaration n) {
      n.f0.accept(this);
      n.f1.accept(this);
      n.f2.accept(this);
   }

   /**
    * f0 -> ( Declaration() )+
    */
   public void visit(DeclarationList n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> StorageClassSpecifier() [ DeclarationSpecifiers() ]
    *       | TypeSpecifier() [ DeclarationSpecifiers() ]
    *       | TypeQualifier() [ DeclarationSpecifiers() ]
    */
   public void visit(DeclarationSpecifiers n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( <AUTO> | <REGISTER> | <STATIC> | <EXTERN> | <TYPEDEF> )
    */
   public void visit(StorageClassSpecifier n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( <VOID> | <CHAR> | <SHORT> | <INT> | <LONG> | <FLOAT> | <DOUBLE> | <SIGNED> | <UNSIGNED> | StructOrUnionSpecifier() | EnumSpecifier() | TypedefName() )
    */
   public void visit(TypeSpecifier n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( <CONST> | <VOLATILE> )
    */
   public void visit(TypeQualifier n) {
      n.f0.accept(this);
   }

   /**

    * f0 -> StructOrUnion()
    * f1 -> ( [ <IDENTIFIER> ] "{" StructDeclarationList() "}" | <IDENTIFIER> )
    */
   public void visit(StructOrUnionSpecifier n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ( <STRUCT> | <UNION> )
    */
   public void visit(StructOrUnion n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( StructDeclaration() )+
    */
   public void visit(StructDeclarationList n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> InitDeclarator()
    * f1 -> ( "," InitDeclarator() )*
    */
   public void visit(InitDeclaratorList n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> Declarator()
    * f1 -> [ "=" Initializer() ]
    */
   public void visit(InitDeclarator n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> SpecifierQualifierList()
    * f1 -> StructDeclaratorList()
    * f2 -> ";"
    */
   public void visit(StructDeclaration n) {
      n.f0.accept(this);
      n.f1.accept(this);
      n.f2.accept(this);
   }

   /**
    * f0 -> TypeSpecifier() [ SpecifierQualifierList() ]
    *       | TypeQualifier() [ SpecifierQualifierList() ]
    */
   public void visit(SpecifierQualifierList n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> StructDeclarator()
    * f1 -> ( "," StructDeclarator() )*
    */
   public void visit(StructDeclaratorList n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ( Declarator() | [ Declarator() ] ":" ConstantExpression() )
    */
   public void visit(StructDeclarator n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> <ENUM>
    * f1 -> ( [ <IDENTIFIER> ] "{" EnumeratorList() "}" | <IDENTIFIER> )
    */
   public void visit(EnumSpecifier n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> Enumerator()
    * f1 -> ( "," Enumerator() )*
    */
   public void visit(EnumeratorList n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> <IDENTIFIER>
    * f1 -> [ "=" ConstantExpression() ]
    */
   public void visit(Enumerator n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> [ Pointer() ]
    * f1 -> DirectDeclarator()
    */
   public void visit(Declarator n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ( t=<IDENTIFIER> | "(" Declarator() ")" )
    * f1 -> ( "[" [ ConstantExpression() ] "]" | "(" ParameterTypeList() ")" | "(" [ IdentifierList() ] ")" )*
    */
   public void visit(DirectDeclarator n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> "*"
    * f1 -> [ TypeQualifierList() ]
    * f2 -> [ Pointer() ]
    */
   public void visit(Pointer n) {
      n.f0.accept(this);
      n.f1.accept(this);
      n.f2.accept(this);
   }

   /**
    * f0 -> ( TypeQualifier() )+
    */
   public void visit(TypeQualifierList n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ParameterList()
    * f1 -> [ "," "..." ]
    */
   public void visit(ParameterTypeList n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ParameterDeclaration()
    * f1 -> ( "," ParameterDeclaration() )*
    */
   public void visit(ParameterList n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> DeclarationSpecifiers()
    * f1 -> ( Declarator() | [ AbstractDeclarator() ] )
    */
   public void visit(ParameterDeclaration n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> <IDENTIFIER>
    * f1 -> ( "," <IDENTIFIER> )*
    */
   public void visit(IdentifierList n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ( AssignmentExpression() | "{" InitializerList() [ "," ] "}" )
    */
   public void visit(Initializer n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> Initializer()
    * f1 -> ( "," Initializer() )*
    */
   public void visit(InitializerList n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> SpecifierQualifierList()
    * f1 -> [ AbstractDeclarator() ]
    */
   public void visit(TypeName n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ( Pointer() | [ Pointer() ] DirectAbstractDeclarator() )
    */
   public void visit(AbstractDeclarator n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( "(" AbstractDeclarator() ")" | "[" [ ConstantExpression() ] "]" | "(" [ ParameterTypeList() ] ")" )
    * f1 -> ( "[" [ ConstantExpression() ] "]" | "(" [ ParameterTypeList() ] ")" )*
    */
   public void visit(DirectAbstractDeclarator n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> <IDENTIFIER>
    */
   public void visit(TypedefName n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( LabeledStatement() | ExpressionStatement() | CompoundStatement() | SelectionStatement() | IterationStatement() | JumpStatement() )
    */
   public void visit(Statement n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( <IDENTIFIER> ":" Statement() | <CASE> ConstantExpression() ":" Statement() | <DFLT> ":" Statement() )
    */
   public void visit(LabeledStatement n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> [ Expression() ]
    * f1 -> ";"
    */
   public void visit(ExpressionStatement n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> "{"
    * f1 -> [ DeclarationList() ]
    * f2 -> [ StatementList() ]
    * f3 -> "}"
    */
   public void visit(CompoundStatement n) {
      n.f0.accept(this);
      n.f1.accept(this);
      n.f2.accept(this);
      n.f3.accept(this);
   }

   /**
    * f0 -> ( Statement() )+
    */
   public void visit(StatementList n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( <IF> "(" Expression() ")" Statement() [ <ELSE> Statement() ] | <SWITCH> "(" Expression() ")" Statement() )
    */
   public void visit(SelectionStatement n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( <WHILE> "(" Expression() ")" Statement() | <DO> Statement() <WHILE> "(" Expression() ")" ";" | <FOR> "(" [ Expression() ] ";" [ Expression() ] ";" [ Expression() ] ")" Statement() )
    */
   public void visit(IterationStatement n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( <GOTO> <IDENTIFIER> ";" | <CONTINUE> ";" | <BREAK> ";" | <RETURN> [ Expression() ] ";" )
    */
   public void visit(JumpStatement n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> AssignmentExpression()
    * f1 -> ( "," AssignmentExpression() )*
    */
   public void visit(Expression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> UnaryExpression() AssignmentOperator() AssignmentExpression()
    *       | ConditionalExpression()
    */
   public void visit(AssignmentExpression n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( "=" | "*=" | "/=" | "%=" | "+=" | "-=" | "<<=" | ">>=" | "&=" | "^=" | "|=" )
    */
   public void visit(AssignmentOperator n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> LogicalORExpression()
    * f1 -> [ "?" Expression() ":" ConditionalExpression() ]
    */
   public void visit(ConditionalExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ConditionalExpression()
    */
   public void visit(ConstantExpression n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> LogicalANDExpression()
    * f1 -> [ "||" LogicalORExpression() ]
    */
   public void visit(LogicalORExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> InclusiveORExpression()
    * f1 -> [ "&&" LogicalANDExpression() ]
    */
   public void visit(LogicalANDExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ExclusiveORExpression()
    * f1 -> [ "|" InclusiveORExpression() ]
    */
   public void visit(InclusiveORExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ANDExpression()
    * f1 -> [ "^" ExclusiveORExpression() ]
    */
   public void visit(ExclusiveORExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> EqualityExpression()
    * f1 -> [ "&" ANDExpression() ]
    */
   public void visit(ANDExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> RelationalExpression()
    * f1 -> [ ( "==" | "!=" ) EqualityExpression() ]
    */
   public void visit(EqualityExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ShiftExpression()
    * f1 -> [ ( "<" | ">" | "<=" | ">=" ) RelationalExpression() ]
    */
   public void visit(RelationalExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> AdditiveExpression()
    * f1 -> [ ( "<<" | ">>" ) ShiftExpression() ]
    */
   public void visit(ShiftExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> MultiplicativeExpression()
    * f1 -> [ ( "+" | "-" ) AdditiveExpression() ]
    */
   public void visit(AdditiveExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> CastExpression()
    * f1 -> [ ( "*" | "/" | "%" ) MultiplicativeExpression() ]
    */
   public void visit(MultiplicativeExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ( "(" TypeName() ")" CastExpression() | UnaryExpression() )
    */
   public void visit(CastExpression n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( PostfixExpression() | "++" UnaryExpression() | "--" UnaryExpression() | UnaryOperator() CastExpression() | <SIZEOF> ( UnaryExpression() | "(" TypeName() ")" ) )
    */
   public void visit(UnaryExpression n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> ( "&" | "*" | "+" | "-" | "~" | "!" )
    */
   public void visit(UnaryOperator n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> ( "[" Expression() "]" | "(" [ ArgumentExpressionList() ] ")" | "." <IDENTIFIER> | "->" <IDENTIFIER> | "++" | "--" )*
    */
   public void visit(PostfixExpression n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> ( <IDENTIFIER> | Constant() | "(" Expression() ")" )
    */
   public void visit(PrimaryExpression n) {
      n.f0.accept(this);
   }

   /**
    * f0 -> AssignmentExpression()
    * f1 -> ( "," AssignmentExpression() )*
    */
   public void visit(ArgumentExpressionList n) {
      n.f0.accept(this);
      n.f1.accept(this);
   }

   /**
    * f0 -> <INTEGER_LITERAL>
    *       | <FLOATING_POINT_LITERAL>
    *       | <CHARACTER_LITERAL>
    *       | <STRING_LITERAL>
    */
   public void visit(Constant n) {
      n.f0.accept(this);
   }

}
