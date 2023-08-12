function patron(x){
    let i;
    let j;


    for(i=x; i>0;i--){
        for(j=0;j<x;j++){
            process.stdout.write(i.toString());
        }
        console.log();
    }
        for(i=2; i<=x;i++){
        for(j=0;j<x;j++){
            process.stdout.write(i.toString());
        }
        console.log();
    }
}

patron(3);