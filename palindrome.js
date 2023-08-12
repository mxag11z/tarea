
function myPalindrome(cadena){
    
    let flag = 0;
    let arrayCadena = cadena.split("");
    let arrayAux = [...arrayCadena];
    let arrayCadenaReverse = arrayCadena.reverse();

    //Verificando si es palindromo o no

    for(i=0;i<arrayCadena.length;i++){
        if(arrayAux[i]!=arrayCadenaReverse[i])
                    flag=1;
    }

    if(flag === 0)
        console.log("Es un palindromo");
    else
        console.log("No es un palindromo");



    
}

myPalindrome('vamos');