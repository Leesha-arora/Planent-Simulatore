function simulate() {
    let steps = document.getElementById("steps").value;

    fetch("http://localhost:5000/simulate?steps=" + steps)
    .then(res => res.text())
    .then(data => {
        document.getElementById("output").innerHTML = "Planet is now in: " + data;
    });
}
