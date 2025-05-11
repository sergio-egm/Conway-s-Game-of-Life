using Plots

# Function to read the .bin files
function load_frame(path::String , size::Int)
    data = read(path)
    grid = reshape(data , size , size)
    return grid
end

function main()
    # Get the size of the lactice and the number of generations
    size , gens = open("INPUT.dat") do io
        x = parse(Int , readline(io))
        y = parse(Int , readline(io))

        return x , y
    end

    animation = @animate for i in 0:gens
        grid = load_frame("data/frame$i.bin" , size)
        heatmap(grid' , colorbar = false , axis = false , title = "Generation $i")
    end

    gif(animation , "life.gif" , fps = 10)
end

main()
