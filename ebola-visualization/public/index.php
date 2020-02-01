<!DOCTYPE html>
<html lang="en">

<head>
    <?php
        require_once "includes/header.php";
        require_once "api.php";
    ?>
    <title>Cellular Automata Visualization</title>
</head>

<body class="bg-gray-100">
<div id="wrapper">
    <!-- Main Content Wrapper -->
    <div id="content-wrapper" class="d-flex flex-column">
        <div id="content">
            <!-- Main Content -->
            <div class="container">
                <div class="row">
                    <div class="col">
                        <div class="text-center">
                            <h1 class="h3 mb-2 mt-4 text-gray-900">Cellular Automata - Data Visualization</h1>
                            <h5><strong>Grid Size:</strong> <?= WORLD_WIDTH ?>x<?= WORLD_HEIGHT ?> | <strong>Total Generations:</strong> <?= GENERATIONS ?></h5>
                            <label id="generation-text" for="gen-slider" class="h5 my-2 mb-2">Generating data..</label>
                            <br>
                            <input type="range" min="1" max="<?= GENERATIONS ?>" value="1" class="slider col-lg-3 mb-4" id="gen-slider">
                            <button class="btn btn-success ml-2" onclick="cycleGenerations(0)"><i class="fas fa-play-circle"></i> Cycle Generations</button>
                            <button class="btn btn-danger ml-2" onclick="stopAnimation()"><i class="fas fa-pause-circle"></i> Stop</button>
                            <div id="grid-display" class="mb-5 mt-1"></div> <!-- Grid Placeholder -->
                        </div>
                    </div>
                    <div class="w-100"></div>
                    <div class="col mt-n4 text-center">
                        <p class="font-weight-bold" id="gen-stats">
                            Total Alive Cells: 0 |
                            Total Infected Cells: 0 |
                            Total Dead Cells: 0 |
                            Total Empty Cells: 0
                        </p>
                    </div>
                </div>
            </div>
            <!-- End of Main Content -->
        </div>
    </div>
</div>
</body>
<?php require_once("includes/footer.php") ?>

<script>
    // Cell state color definitions.
    var CELL_STATES = [
        "#FFFFFF", // Empty.
        "#00FF00", // Healthy.
        "#FF0000", // Infected.
        "#000000", // Dead.
        "#FFFF00", // Invulnerable.
    ];

    // Cellular Automata variables.
    var CELL_DATA; // Variable to hold JSON array data.
    var WORLD_WIDTH = <?= WORLD_WIDTH ?>;
    var WORLD_HEIGHT = <?= WORLD_HEIGHT ?>;
    var GENERATIONS = <?= GENERATIONS ?>;
    var ANIM_SPEED = 700; // ms.

    // Cell counters.
    var CELL_STATS = [0, 0, 0, 0, 0];

    // Function to create the grid.
    function createGrid(width, height)
    {
        for (var row = 0; row < width; row++)
        {
            for (var col = 0; col < height; col++)
            {
                $("#grid-display").append("<div class='grid' id='grid-" + row + "-" + col +"' title='X: " + row + ", Y: " + col + "'></div>");
                $("#grid-" + row + "-" + col).width(960 / width).height(960 / width);
            }
        }
    }

    // Set's the specified cell's state colour.
    function setCellState(x, y, state) { $("#grid-" + x + "-" + y).css("background-color", CELL_STATES[state]); }

    // Sets the grid to display the specified generation.
    function setGridGeneration(generation)
    {
        console.log("Playing generation " + generation + "..");
        CELL_STATS = [0, 0, 0, 0, 0];
        for (var row = 0; row < WORLD_WIDTH; row++)
        {
            for (var col = 0; col < WORLD_HEIGHT; col++)
            {
                var cellState = CELL_DATA[generation][row][col];
                setCellState(row, col, cellState);
                CELL_STATS[cellState]++;
            }
        }

        // Update statistics text.
        $("#gen-stats").html(
            "Total Healthy Cells: <span style='color: " + CELL_STATES[1] + ";'>" + CELL_STATS[1] + "</span>" +
            " | Total Infected Cells: <span style='color: " + CELL_STATES[2] + ";'>" + CELL_STATS[2] + "</span>" +
            " | Total Dead Cells: <span style='color: " + CELL_STATES[3] + ";'>" + CELL_STATS[3] + "</span>" +
            " | Total Empty Cells: " + CELL_STATS[0]
        );

        // Update generation counter and slider position.
        $("#generation-text").text("Generation: " + generation);
        $("#gen-slider").val(generation);
    }

    // Load grid details from API and create it.EP
    $(document).ready(function() {
        createGrid(WORLD_WIDTH, WORLD_HEIGHT);

        $.getJSON("data.json", function(data) {
            CELL_DATA = data;
            setGridGeneration(1);
            $("#generation-text").text("Generation: 1");
        });
    });

    // Event handler for generation slider movement.
    $("#gen-slider").on("input", function () {
        setGridGeneration($("#gen-slider").val());
    });

    // Function to automatically cycle generations when button pressed.
    function cycleGenerations(generation)
    {
        var delay = 0;
        for (var i = 0; i < GENERATIONS; i++)
        {
            setTimeout(setGridGeneration, delay, ++generation);
            delay += ANIM_SPEED;
        }
    }

    function stopAnimation()
    {
        var id = window.setTimeout(function() {}, 0);

        while (id--) { window.clearTimeout(id); }
    }
</script>
</html>