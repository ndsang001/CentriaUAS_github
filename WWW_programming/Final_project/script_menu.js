if (document.readyState == "loading") {
    document.addEventListener('DOMContentLoaded', ready)
} else {
    ready()
}

function ready() {
    var menuListData = {
        "items": [
            { "itemName": "Lohi", "itemImage": "menu_sushi_list/lohi.jpeg", "itemPrice": 3.5, "itemQuantity": 2 },
            { "itemName": "Futomaki", "itemImage": "menu_sushi_list/futomaki.jpeg", "itemPrice": 10.5, "itemQuantity": 8 },
            { "itemName": "Kasvisrulla", "itemImage": "menu_sushi_list/kasvisrulla.jpeg", "itemPrice": 4.5, "itemQuantity": 10 }
        ]
    }

    showMenuList(menuListData)

    var addToCartButtons = document.getElementsByClassName('shop_item_button')
    for (let i = 0; i < addToCartButtons.length; ++i) {
        var button = addToCartButtons[i]
        button.addEventListener('click', addToCartClicked)
    }

    var removeCartItemButtons = document.getElementsByClassName('btn_danger')
    console.log(removeCartItemButtons)
    for (let i = 0; i < removeCartItemButtons.length; ++i) {
        var button = removeCartItemButtons[i]
        button.addEventListener('click', removeCartItem)
    }

    var quantityInputs = document.getElementsByClassName('cart_quantity_input')
    for (let i = 0; i < quantityInputs.length; ++i) {
        var input = quantityInputs[i]
        input.addEventListener('change', quantityChanged)
    }
}

function showMenuList(menuListData) {
    var itemList = document.getElementsByClassName('items')[0]

    for (let i in menuListData.items) {
        console.log(menuListData.items.length)
        var item = document.createElement('div')
        item.classList.add('item')
        var menuListContent = `
            <span class="name_of_item">${menuListData.items[i].itemName}</span>
            <img class="item_image" src="${menuListData.items[i].itemImage}">
            <div class="item_detail">
                <span class="price">${menuListData.items[i].itemPrice}€</span>
                <span class="quantity">${menuListData.items[i].itemQuantity}pcs</span>
                <button class="btn btn_primary shop_item_button" type="button">ADD TO CART</button>
            </div>`

        item.innerHTML += menuListContent
        itemList.append(item)
    }
}

function removeCartItem(event) {
    var buttonClicked = event.target
    buttonClicked.parentElement.parentElement.remove()
    updateCartTotal()
}

function quantityChanged(event) {
    var input = event.target
    if (isNaN(input.value) || input.value <= 0) {
        input.value = 1
    }
    updateCartTotal()
}

function addToCartClicked(event) {
    var button = event.target
    var shopItem = button.parentElement.parentElement
    var itemName = shopItem.getElementsByClassName('name_of_item')[0].innerText
    var itemPrice = shopItem.getElementsByClassName('price')[0].innerText
    var itemImage = shopItem.getElementsByClassName('item_image')[0].src
    console.log(itemName, itemPrice, itemImage)
    addItemToCart(itemName, itemPrice, itemImage)
    updateCartTotal()
}

function addItemToCart(itemName, itemPrice, itemImage) {
    var cartRow = document.createElement('div')
    cartRow.classList.add('cart_row')
    var cartItems = document.getElementsByClassName('cart_items')[0]
    var cartItemNames = cartItems.getElementsByClassName('cart_item_title')
    for (let i = 0; i < cartItemNames.length; ++i) {
        if (cartItemNames[i].innerText == itemName) {
            alert('This item is already added to the cart')
            return
        }
    }
    var cartRowContents = `
        <div class="cart_item cart_column">
            <img class="cart_item_image" src="${itemImage}">
            <span class="cart_item_title">${itemName}</span>
        </div>
            <span class="cart_price cart_column">${itemPrice}</span>
        <div class="cart_quantity cart_column">
            <input class="cart_quantity_input" type="number" value="1">
            <button class="btn btn_danger" type="button">REMOVE</button>
        </div>`

    cartRow.innerHTML = cartRowContents
    cartItems.append(cartRow)
    cartRow.getElementsByClassName('btn_danger')[0].addEventListener('click', removeCartItem)
    cartRow.getElementsByClassName('cart_quantity_input')[0].addEventListener('change', quantityChanged)
}

function updateCartTotal() {
    var cartItemContainer = document.getElementsByClassName('cart_items')[0]
    var cartRows = cartItemContainer.getElementsByClassName('cart_row')
    total = 0
    for (let i = 0; i < cartRows.length; ++i) {
        var cartRow = cartRows[i]
        var priceElement = cartRow.getElementsByClassName('cart_price')[0]
        var quantityElement = cartRow.getElementsByClassName('cart_quantity_input')[0]
        console.log(priceElement, quantityElement)
        var price = parseFloat(priceElement.innerText.replace('€', ''))
        console.log(price)
        var quantity = quantityElement.value
        console.log(price * quantity)
        total += price * quantity
    }
    total = Math.round(total * 100) / 100
    document.getElementsByClassName('cart_total_price')[0].innerText = total + '€'
}