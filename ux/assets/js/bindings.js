function HandleButton(elmnt) {
    // call bound function for chosen case
    document.getElementsByClassName("active")[0].className = "disabled";
    switch (elmnt) {
        case "Dashboard":
            // disable active and set new active
            console.log("Dashboard clicked");
            document.getElementById("liDashboard").className = "active";
            var selectedClass = btnDashboard();
            break;
        case "Search":
            // disable active and set new active
            console.log("Search clicked");
            document.getElementById("liSearch").className = "active";
            var selectedClass = btnSearch();
            break;
        case "Favorites":
            // disable active and set new active
            console.log("Favorites clicked");
            document.getElementById("liFavorites").className = "active";
            var selectedClass = btnFavorites();
            break;
        case "Help":
            // disable active and set new active
            console.log("Help clicked");
            document.getElementById("liHelp").className = "active";
            var selectedClass = btnHelp();
            break;
    }
};
