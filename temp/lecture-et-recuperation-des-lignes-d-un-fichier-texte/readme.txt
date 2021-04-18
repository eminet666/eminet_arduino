Lecture et récupération des lignes d'un fichier texte-----------------------------------------------------
Url     : http://codes-sources.commentcamarche.net/source/45936-lecture-et-recuperation-des-lignes-d-un-fichier-texteAuteur  : PetoleTeamDate    : 06/08/2013
Licence :
=========

Ce document intitulé « Lecture et récupération des lignes d'un fichier texte » issu de CommentCaMarche
(codes-sources.commentcamarche.net) est mis à disposition sous les termes de
la licence Creative Commons. Vous pouvez copier, modifier des copies de cette
source, dans les conditions fixées par la licence, tant que cette note
apparaît clairement.

Description :
=============

But du Jeu...
<br />- R&eacute;cup&eacute;rer chaque ligne d'un fichier texte &
agrave; des fins de traitement divers. 
<br />
<br />Principe...
<br />- Ouvr
ir le fichier texte dans une IFRAME, 
<br />- transf&eacute;rer le contenu dans
 une TEXTAREA 
<br />- r&eacute;cup&eacute;rer les diff&eacute;rentes lignes da
ns un ARRAY pour en faire ce que bon vous semble. 
<br />
<br />Utilisation...

<br />- Permet de ne plus modifier la page HTML mais seulement le fichier text
e. 
<br />
<br />Deux fichiers exemples sont la pour vous indiquer deux mises 
en oeuvre de cette approche.
<br /><a name='source-exemple'></a><h2> Source / E
xemple : </h2>
<br /><pre class='code' data-mode='basic'>
&lt;script type=&qu
ot;text/javascript&quot;&gt;
//-------------------------
function Read_File( w
here_){
  //-- Recup des Objets
  var szTmp  =&quot;&quot;;
  var O_Src  = do
cument.getElementById( 'I_RECUP').contentWindow.document;
  var O_Dest = docume
nt.getElementById( 'T_RECUP');
  if( O_Src.body){
    O_Src = O_Src.body;
   
 //-- Lecture du contenu
    if( O_Src.textContent)
      szTmp = O_Src.textCo
ntent;
    //-- Cas IE
    else if (O_Src.innerText)
      szTmp = O_Src.inne
rText;
    //-- cas NetScape a part
    else if( O_Src.innerHTML){
      szTm
p = O_Src.innerHTML;
      szTmp = szTmp.replace(/&lt;/gi, &quot;\&lt;&quot;);

      szTmp = szTmp.replace(/&gt;/gi, &quot;\&gt;&quot;);
      szTmp = szTmp.
replace(/&lt;pre&gt;/gi, &quot;&quot;);
      szTmp = szTmp.replace(/&lt;\/pre&
gt;/gi, &quot;&quot;);
    }
  }
  else
    szTmp = &quot;ERREUR Format Fich
ier&quot;;

  //-- Transfert dans TEXTAREA
  O_Dest.value = szTmp;
  //-- Re
cuperation des lignes
  var O_Src  = document.getElementById( 'T_RECUP');
  va
r O_Dest = document.getElementById( where_);

  if( O_Dest){
    szTmp =&quot
;&quot;;
    //-- Supprime &quot;\r&quot; pour IE et Opera
    O_Src.value = O
_Src.value.replace(/\r/gi, &quot;&quot;)
    //-- Recup donnee
    var T_Lig =
 O_Src.value.split('\n');
    //-- Supprime ligne vide en fin de fichier
     
while(!T_Lig[T_Lig.length-1].replace(/\s/g,''))
       T_Lig.length --;//= T_Li
g.length-1;
    //-- Pour tous les lignes
    for( var i=0; i &lt;T_Lig.length
; i++){
      szTmp += T_Lig[i] +'&lt;br&gt;';
    }
    //-- Ecrit le result
at
    O_Dest.innerHTML = szTmp;
  }
}
&lt;/script&gt;
</pre>
<br /><a nam
e='conclusion'></a><h2> Conclusion : </h2>
<br />Laisser libre court &agrave; 
votre imagination...
