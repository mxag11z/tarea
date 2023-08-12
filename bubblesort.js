
function bubbleSort(array){
    let i;
    let j;
    let aux;
    //passes
    for(i=0;i<array.length;i++)
        {
            //comparaciones
            for(j=0;j<array.length-i;j++)
            {
                if(array[j]>array[j+1])
                {
                    temp= array[j];
                    array[j]=array[j+1];
                    array[j+1]=temp;
                }
            }
        
        }
    console.log(array);
}

let array = [0,1,0,2,-1];

bubbleSort(array);